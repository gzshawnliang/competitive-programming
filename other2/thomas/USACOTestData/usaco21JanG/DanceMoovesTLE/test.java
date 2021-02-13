import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
 
public class DanceMooves {
 
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        long k = Integer.parseInt(tokenizer.nextToken());
        long m = Long.parseLong(tokenizer.nextToken());
        int[] cows = new int[n + 1];
        List<View>[] views = new List[n + 1];
        for (int j = 1; j <= n; j++) {
            cows[j] = j;
            views[j] = new ArrayList<>();
            views[j].add(new View(j, 0));
        }
        for (long t = 1; t <= k; t++) {
            tokenizer = new StringTokenizer(in.readLine());
            int a = Integer.parseInt(tokenizer.nextToken());
            int b = Integer.parseInt(tokenizer.nextToken());
            int c = cows[a];
            int d = cows[b];
            cows[a] = d;
            cows[b] = c;
            views[cows[a]].add(new View(a, t));
            views[cows[b]].add(new View(b, t));
        }
        int[] answer = new int[n + 1];
        for (int r = 1; r <= n; r++) {
            if (cows[r] != 0) {
                List<Integer> cycle = new ArrayList<>();
                int j = r;
                while (cows[j] != 0) {
                    cycle.add(j);
                    j = cows[j];
                    cows[cycle.get(cycle.size() - 1)] = 0;
                }
                Map<Integer, List<Interval>> intervalMap = new HashMap<>();
                for (j = 0; j < cycle.size(); j++) {
                    for (View view : views[cycle.get(j)]) {
                        if (m >= view.time) {
                            int covered = (int) Math.min((long) cycle.size(), ((m - view.time) / k) + 1L);
                            if (!intervalMap.containsKey(view.position)) {
                                intervalMap.put(view.position, new ArrayList<>());
                            }
                            intervalMap.get(view.position).add(new Interval(j, Math.min(cycle.size(), j + covered)));
                            if (j + covered > cycle.size()) {
                                intervalMap.get(view.position).add(new Interval(0, (j + covered) % cycle.size()));
                            }
                        }
                    }
                }
                int[] amts = new int[cycle.size() + 1];
                for (List<Interval> intervals : intervalMap.values()) {
                    intervals.sort(Comparator.comparingInt(interval -> interval.from));
                    int prev = 0;
                    for (Interval interval : intervals) {
                        amts[Math.max(prev, interval.from)]++;
                        prev = Math.max(prev, interval.until);
                        amts[prev]--;
                    }
                }
                for (j = 0; j < cycle.size(); j++) {
                    answer[cycle.get(j)] = amts[j];
                    amts[j + 1] += amts[j];
                }
            }
        }
        StringBuilder out = new StringBuilder();
        for (int j = 1; j <= n; j++) {
            out.append(answer[j]).append('\n');
        }
        System.out.print(out);
    }
 
    static class View {
        final int position;
        final long time;
 
        View(int position, long time) {
            this.position = position;
            this.time = time;
        }
    }
 
    static class Interval {
        final int from;
        final int until;
 
        Interval(int from, int until) {
            this.from = from;
            this.until = until;
        }
    }
}