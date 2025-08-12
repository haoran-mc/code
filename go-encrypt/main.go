package main

import (
	"crypto/aes"
	"crypto/cipher"
	"crypto/ed25519"
	"crypto/hmac"
	"crypto/rand"
	"crypto/sha256"
	"fmt"
	"io"
	"log"

	"golang.org/x/crypto/argon2"
	"golang.org/x/crypto/hkdf"
)

func main() {
	fmt.Println("--- AES-GCM ---")
	myAesGcm()

	fmt.Println("--- HMAC-SHA256 ---")
	myHmacSha256()

	fmt.Println("--- Argon2 ---")
	myArgon2()

	fmt.Println("--- Ed25519 ---")
	myEd25519()

	fmt.Println("--- HKDF ---")
	myHkdf()
}

func myAesGcm() {
	// The key should be 16 bytes (AES-128) or 32 bytes (AES-256) long.
	key := make([]byte, 32)
	if _, err := rand.Read(key); err != nil {
		log.Fatal(err)
	}

	plaintext := []byte("example plaintext")

	block, err := aes.NewCipher(key)
	if err != nil {
		log.Fatal(err)
	}

	gcm, err := cipher.NewGCM(block)
	if err != nil {
		log.Fatal(err)
	}

	nonce := make([]byte, gcm.NonceSize())
	if _, err := io.ReadFull(rand.Reader, nonce); err != nil {
		log.Fatal(err)
	}

	ciphertext := gcm.Seal(nonce, nonce, plaintext, nil)
	fmt.Printf("Ciphertext: %x\n", ciphertext)

	decrypted, err := gcm.Open(nil, nonce, ciphertext[gcm.NonceSize():], nil)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Printf("Decrypted: %s\n", decrypted)
}

func myHmacSha256() {
	secret := []byte("my-secret-key")
	message := []byte("my-message")

	h := hmac.New(sha256.New, secret)
	h.Write(message)
	signature := h.Sum(nil)

	fmt.Printf("Signature: %x\n", signature)

	// To verify
	h2 := hmac.New(sha256.New, secret)
	h2.Write(message)
	expectedSignature := h2.Sum(nil)

	fmt.Printf("Verification successful: %t\n", hmac.Equal(signature, expectedSignature))
}

func myArgon2() {
	password := []byte("my-secret-password")
	salt := make([]byte, 16)
	if _, err := rand.Read(salt); err != nil {
		log.Fatal(err)
	}

	// Argon2id is the recommended variant
	hash := argon2.IDKey(password, salt, 1, 64*1024, 4, 32)

	fmt.Printf("Salt: %x\n", salt)
	fmt.Printf("Hash: %x\n", hash)

	// Verification
	hash2 := argon2.IDKey(password, salt, 1, 64*1024, 4, 32)
	fmt.Printf("Verification successful: %t\n", hmac.Equal(hash, hash2))
}

func myEd25519() {
	publicKey, privateKey, err := ed25519.GenerateKey(rand.Reader)
	if err != nil {
		log.Fatal(err)
	}

	message := []byte("message to be signed")
	signature := ed25519.Sign(privateKey, message)

	fmt.Printf("Public Key: %x\n", publicKey)
	fmt.Printf("Signature: %x\n", signature)

	// Verification
	verified := ed25519.Verify(publicKey, message, signature)
	fmt.Printf("Verification successful: %t\n", verified)
}

func myHkdf() {
	// Master secret from which other keys are derived
	masterSecret := []byte("my-master-secret")
	// Salt should be random and non-secret
	salt := make([]byte, 16)
	if _, err := rand.Read(salt); err != nil {
		log.Fatal(err)
	}

	// Create a new HKDF-SHA256 instance
	hkdf := hkdf.New(sha256.New, masterSecret, salt, nil)

	// Derive a 32-byte key for encryption
	encryptionKey := make([]byte, 32)
	if _, err := io.ReadFull(hkdf, encryptionKey); err != nil {
		log.Fatal(err)
	}

	// Derive another 16-byte key for authentication
	authenticationKey := make([]byte, 16)
	if _, err := io.ReadFull(hkdf, authenticationKey); err != nil {
		log.Fatal(err)
	}

	fmt.Printf("Encryption Key: %x\n", encryptionKey)
	fmt.Printf("Authentication Key: %x\n", authenticationKey)
}
