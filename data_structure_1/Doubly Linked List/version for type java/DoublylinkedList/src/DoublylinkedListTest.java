
import java.nio.IntBuffer;

public class DoublylinkedListTest {
   private Node Head;
   private Node Temp;
   private int Count;
   
   public DoublylinkedListTest() {
      Count = 0;
   }
   
   private class Node{
      
      private Node Next;
      private Node Prev;
      private int data;
      
      Node(int position,int data){
         this.data = data;
         this.Next = null;
         this.Prev = null;
      }
   }
   
   public void Insert(int Position, int Item) {
   Node newNode = new Node(Position, Item);
   newNode.Next = null;
   newNode.data = Item;

      if (Head != null) {

         Temp = Head;

         if ((Count+1) == Position) {
            for (int i = 1; i < (Position - 1); i++) {
               Temp = Temp.Next;
            }
            Temp.Next = newNode;
            newNode.Prev = Temp;
         }
         else {
            for (int i = 1; i < Position; i++) {
               Temp = Temp.Next;
            }
            newNode.Prev = Temp.Prev;
            Temp.Prev = newNode;
            newNode.Next = newNode.Prev.Next;
            newNode.Prev.Next = newNode;
         }
      }
      else {
         Head = newNode;
      }

      Count += 1;
   }

   public void Delete(int Position) {
       if (IsEmpty())
          System.out.println("Deletion on Empty List");
         else if ((Position > Count) || (Position < 1))
           System.out.println("Position out of Range");
         else
         {
            Temp = Head;
            if (Position == 1) {
               Head = Head.Next;
            }
            else {
               for (int i = 1; i < Position; i++) {
                  Temp = Temp.Next;
               }
               Temp.Next.Prev = Temp.Prev;
               Temp.Prev.Next = Temp.Next;
            }
            Count -= 1;
         }
   }
   public void Retrieve (int Position, int item) {
      if (IsEmpty()) {
         System.out.println("Deletion on Empty List");
      }
      else if ((Position > Count) || (Position < 1)) {
         System.out.println("Position out of Range"); 
      }
      else {
            Temp = Head;
            for (int i = 1; i < Position; i++) {
               Temp = Temp.Next;
            }
            item = Temp.data;
               System.out.println("item : " + item);
         }
   }
   
   public boolean IsEmpty() {
         return (Count == 0);
   }
   public int Length() {
      System.out.println("Length is " + Count);
         return 0;
      }
   public String toString() {
         StringBuffer result = new StringBuffer("[");
         if(Count != 0) {
            Node node = Head;
            result.append(node.data);
            while(node.Next != null) {
               node = node.Next;
               result.append(", ");
               result.append(node.data);
            }
         }
         result.append("]");
         return result.toString();
      }
}

