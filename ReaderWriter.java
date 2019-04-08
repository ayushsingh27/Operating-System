import java.util.concurrent.Semaphore;
public class ReaderWriter {
    static int readcount=0;
    static Semaphore S=new Semaphore(1);
    static Semaphore wrt=new Semaphore(1);
    
    static class Reader implements Runnable{
        public void run(){
            try{
                S.acquire();
                readcount++;
                if(readcount==1)
                    wrt.acquire();
                S.release();
                System.out.println(Thread.currentThread()+" raju started Reading");
                Thread.sleep(1000);
                System.out.println(Thread.currentThread()+"raju is Still Reading");
                S.acquire();
                readcount--;
                if(readcount==0)
                        wrt.release();
                S.release();
            }
            catch(Exception e){
                System.out.println(e);
            }
        }
    }   
        static class Writer implements Runnable{
            public void run(){
                try{
                    wrt.acquire();
                    System.out.println(Thread.currentThread()+"chetan bhagat started Writing");
                    Thread.sleep(1000);
                    System.out.println(Thread.currentThread()+" chetan bhagat is Still Writing");
                    wrt.release();
                }
                catch(Exception e){
                    System.out.println(e);
                }
            }
        }

    public static void main(String[] args) {
        Reader r=new Reader();
        Writer w=new Writer();
        Thread t1=new Thread(r);
        Thread t2=new Thread(r);
        Thread t3=new Thread(w);
        t1.start();
        t2.start();
        t3.start();
    }
    
}