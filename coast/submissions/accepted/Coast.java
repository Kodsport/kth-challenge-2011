/* Solution to "Coast Length" from KTH Challenge 2011
** Author: Lukas Polacek
*/

import java.io.*;
import java.util.*;

public class Coast {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int n = sc.nextInt(), m = sc.nextInt();
        char a[][] = new char[n + 2][m + 2];
        for (int i = 0; i < n + 2; i++)
            for (int j = 0; j < m + 2; j++)
                a[i][j] = '0';

        sc.nextLine();
        for (int i = 0; i < n; i++)
        {
            String s = sc.nextLine();
            for (int j = 0; j < m; j++)
                a[i + 1][j + 1] = s.charAt(j);
        }
        LinkedList<Integer> q = new LinkedList<Integer>();
        q.add(0); q.add(0);
        a[0][0] = '#';

        int dx[] = new int[]{0, 1, 0, -1};
        int dy[] = new int[]{1, 0, -1, 0};
        int res = 0;
        while (!q.isEmpty())
        {
            int x = q.getFirst(); q.removeFirst();
            int y = q.getFirst(); q.removeFirst();
            for (int k = 0; k < 4; k++)
            {
                int s = x + dx[k];
                int t = y + dy[k];
                if (s < 0 || s >= n + 2 || t < 0 || t >= m + 2)
                    continue;
                if (a[s][t] == '1')
                    res++;
                if (a[s][t] != '0')
                    continue;
                a[s][t] = '#';
                q.add(s); q.add(t);
            }
        }
        System.out.println(res);
    }
}
