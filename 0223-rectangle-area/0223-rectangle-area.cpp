class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int xOverlap, yOverlap, x1, x2, y1, y2;
        
        x1 = min(ax2, bx2);
        x2 = max(ax1, bx1);
        xOverlap = x1-x2;
        
        y1 = min(ay2, by2);
        y2 = max(ay1, by1);
        yOverlap = y1-y2;
        
        int area1 = abs(ax1-ax2)*abs(ay1-ay2);
        int area2 = abs(bx1-bx2)*abs(by1-by2);
        
        int commonArea = 0;
        if(xOverlap > 0 && yOverlap > 0)
            commonArea = abs(x1-x2)*abs(y1-y2);
        
        return area1+area2-commonArea;
    }
};