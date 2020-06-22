//---------------------
//Hello.java
//(c) H.Buchmann FHNW 2020
//---------------------
package example;
import com.amazonaws.services.lambda.runtime.Context;
import com.amazonaws.services.lambda.runtime.RequestHandler;

public class Hello implements RequestHandler<String,String>
{
 public String handleRequest(String event,Context context)
 {
  return event+" HelloWorld";
 }
 
 public static void main(String args[])
 {
  System.out.println(new Hello().handleRequest("12345",null));
 }
}
