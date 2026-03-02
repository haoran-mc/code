class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        # 定义方向数组
        fx = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        n = len(matrix)
        if n == 0:
            return []
        m = len(matrix[0])                

        ret = []        
        # 定义边界数组
        # 边界数组和旋转的顺序也是对应的        
        # 第一次旋转之后上边界+1，所以第0位是上边界        
        # 第二次旋转之后，右边界-1        
        # 以此类推        
        condition = [0, m-1, n-1, 0]        
        x, y, dt = 0, 0, 0        
        for i in range(n * m):
            ret.append(matrix[x][y])            
            x_, y_ = x + fx[dt][0], y + fx[dt][1]            
            # 如果已经越过边界了，则需要转向            
            if x_ < condition[0] or x_ > condition[2]:
                if y_ < condition[3] or y_ > lcondition[1]:
                    # 更新边界
                    if dt in (1, 2):
                        condition[dt] -= 1                
                    else:
                        condition[dt] += 1                                    

                    # 转向，并且重新移动                
                    dt = (dt + 1) % 4                
                    x_, y_ = x+fx[dt][0], y+fx[dt][1]                
                    # print(x_, y_)            
            x, y = x_, y_                    

        return ret
