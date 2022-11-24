import java.util.*;

public class TrappingRainwater {
    public static int trappingRainwater(int height[]) {
        // find left maximum boundary array
        int leftMax[] = new int[height.length];
        leftMax[0] = height[0];
        for (int i = 1; i < height.length; i++) {
            leftMax[i] = Math.max(height[i], leftMax[i - 1]);
        }
        // find right maximum boundary array
        int rightMax[] = new int[height.length];
        rightMax[height.length - 1] = height[height.length - 1];
        for (int i = height.length - 2; i >= 0; i--) {
            rightMax[i] = Math.max(height[i], rightMax[i + 1]);
        }
        // finding trapped rainwater
        int trappedwater = 0;
        for (int i = 0; i < height.length; i++) {
            int waterlevel = Math.min(leftMax[i], rightMax[i]);
            trappedwater += waterlevel - height[i];
        }
        return trappedwater;
    }

    public static void main(String args[]) {
        // let's take an example of height=4,2,0,6,3,2,5.
        int height[] = { 4, 2, 0, 6, 3, 2, 5 };
        System.out.println(trappingRainwater(height));
    }
}
