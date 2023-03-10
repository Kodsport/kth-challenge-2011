/* Solution to "Reversed Binary Numbers" from KTH Challenge 2011
** Author: Emma Enström
*/
import java.io.*;

public class Binary {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String nr = Long.toBinaryString(Long.parseLong(in.readLine()));
        long ans = 0;
        for (int i = nr.length()-1;i>=0;i--) {
            int pos = Character.getNumericValue(nr.charAt(i));
            ans += pos << i;
        }
        System.out.println(ans);
    }
}
