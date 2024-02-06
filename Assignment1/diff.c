#include <stdlib.h>

/*Step 5 : */

/*Return 0 if ds1 and ds2 are clones,
 * else return -1*/
int
diff (void *root1,    /*pointer to Data structure 1*/
      void *root2,    /*pointer to data structure 2*/
      void *(*iterator(void *)), /*Iterator function callback*/
      int comparator(void *, void *),
      void *(*get_app_data(void *))){  /*Comparison function callback*/

      /*Write your code here*/
        
      void *data1;
      void *data2;

      void *temp1 = root1 , *temp2 = root2;

      if( !root1 && root2 )
          return -1;
      else if( root1 && !root2 )
          return -1;

      if( comparator(get_app_data(temp1),get_app_data(temp2)))
          return -1;

      while( temp1 != NULL && temp2 != NULL ){

            data1 =get_app_data(temp1);
            data2 = get_app_data(temp2);

            if( comparator(data1,data2) == -1 ){
                return -1;
            }

            temp1 = iterator(temp1);
            temp2 = iterator(temp2);
      }

      if( temp1 == NULL && temp2 != NULL )
          return -1;
      else if( temp1 != NULL && temp2 == NULL )
          return -1;

      return 0;
}
