package spark;

import java.util.Map;
import java.util.Set;
import java.util.concurrent.ConcurrentHashMap;

public class Thread20s extends Thread{
	public static Map<Integer, String> cache;
	public static Map<Integer, Long> cache10s;
	public static Map<Integer, Long> cache20s;
	
	public Thread20s(Map<Integer, Long> m1, Map<Integer, Long> m2, Map<Integer, String> c) {
		cache = c;
		cache10s = m1;
		cache20s = m2;
	}
	
	@Override
	public void run() {
		while(true) {
			Set<Integer> listKey = cache20s.keySet();
			if(listKey.size() == 0) continue;
			for(Integer integer : listKey) {
				if(System.currentTimeMillis() - cache20s.get(integer) >= 20000) {
					cache20s.remove(integer);
					System.out.println("remove : " + integer);
					cache.remove(integer);
				}
			}
		}
	}
}
