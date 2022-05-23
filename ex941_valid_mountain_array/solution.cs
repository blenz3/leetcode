public class Solution {
    public bool ValidMountainArray(int[] arr) {
        if(arr.Length < 3) return false;
        int incIndex=0;
        while(incIndex < arr.Length-2 && arr[incIndex] < arr[incIndex+1]){ 
            incIndex++;
        }
    
        int decIndex=arr.Length-1;
        while(decIndex > 1 && arr[decIndex] < arr[decIndex-1]){ 
            decIndex--;
        }
        //Console.WriteLine($"inc {incIndex}, dec {decIndex}");
        return incIndex == decIndex;
    }
}
