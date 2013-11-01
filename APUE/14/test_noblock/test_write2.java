import java.io.*;

public class test_write2 {
	    public static void main( String[ ] args ) throws Exception {
			int n;
			PrintWriter pw = new PrintWriter( new FileWriter( "java.file" ) );
			for(n = 0; n < 1000000; n++){
				pw.print("ddddddddddd\n" );
			}
			pw.close();
		}
}
