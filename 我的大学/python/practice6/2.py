import wordcloud
file = open("cloud.txt", "r")
text = file.read()
file.close()
wcloud = wordcloud.WordCloud().generate(text)
wcloud.to_file("photo.png")
