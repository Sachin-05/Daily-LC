class Solution {
    public int minOperations(int[][] grid, int x) {
       List <Integer> arr = new ArrayList<>();

       int m = grid.length;
       int n = grid[0].length;

       for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            arr.add(grid[i][j]);
        }
       }

       int rem = arr.get(0) %x;

       for(int num : arr){
        if(num%x != rem){
            return -1;
        }
       }

       Collections.sort(arr);
       int target = arr.get(arr.size()/2);

       int ans=0;

       for(int num : arr){
        ans += Math.abs(num-target) / x;
       }
       return ans;
    }
}
