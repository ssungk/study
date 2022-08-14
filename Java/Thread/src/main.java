
import java.util.concurrent.*;

public class main {
    public static void main(String[] args) throws InterruptedException, ExecutionException {
        ExecutorService executorService = Executors.newSingleThreadExecutor();

        java.util.concurrent.Callable<String> hello = () -> {
            Thread.sleep(2000L);
            return "Hello";
        };
        // 1. Future type 을 submit의 리턴으로 사용
        Future<String> helloFuture = executorService.submit(hello);
        System.out.println("Started!");

        // 2. blocking call
        try {
            helloFuture.get(1000, TimeUnit.MILLISECONDS);
        }
        catch (TimeoutException ignore)
        {

        }

        System.out.println("End!!");
        executorService.shutdown();
    }
}