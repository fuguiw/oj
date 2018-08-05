public class Hindexii {
    public int hIndex(int[] citations) {
        int begin = 0;
        int end = citations.length - 1;
        int h = 0;

        while (begin <= end) {
            int middle = begin + (end - begin) / 2;
            int c = citations[middle];
            int n = citations.length - middle;

            if (n > c) {
                h = Math.max(h, c);
                begin++;
            } else if (n < c) {
                h = Math.max(h, n);
                end--;
            } else {
                h = c;
                break;
            }
        }

        return h;
    }
}
