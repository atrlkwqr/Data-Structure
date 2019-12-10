public class MainClass {

   public static void main(String[] args) {
      // TODO Auto-generated method stub
	   DoublylinkedListTest integer = new DoublylinkedListTest();
         int item = 0;

         integer.Insert(1, 1);
         integer.Insert(2, 2);
         integer.Insert(3, 3);
         System.out.println(integer.toString());
         integer.Insert(3, 4);
         System.out.println(integer.toString());
         integer.Insert(5, 2);
         System.out.println(integer.toString());
         integer.Delete(4);
         System.out.println(integer.toString());
         integer.Delete(1);
         System.out.println(integer.toString());
         integer.Length();
         System.out.println(integer.toString());
         integer.Retrieve(2, item);

      }
}