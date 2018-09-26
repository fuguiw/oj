import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class PossibleBipartition {

    List<Integer>[] graph;
    Map<Integer, Integer> colors;


    public boolean possibleBipartition(int N, int[][] dislikes) {
        graph = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int[] edge : dislikes) {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }

        colors = new HashMap<>();
        for (int i = 1; i <= N; i++) {
            if (!colors.containsKey(i) && !dfs(i, 0)) {
                return false;
            }
        }
        return true;
    }

    private boolean dfs(int node, int color) {
        if (colors.containsKey(node)) {
            return colors.get(node) == color;
        }
        colors.put(node, color);

        for (int neighbor : graph[node]) {
            if (!dfs(neighbor, 1 - color)) {
                return false;
            }
        }
        return true;
    }
}
