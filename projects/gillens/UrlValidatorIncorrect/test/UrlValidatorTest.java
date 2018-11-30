import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   public void assert_gen(String url, UrlValidator urlVal, Boolean expected_true) {
	   if (expected_true) {
		   assert_true(url, urlVal);
	   }
	   else {
		   assert_false(url, urlVal);
	   }
   }
   
   public void assert_true(String url, UrlValidator urlVal) {
	   //print nothing if it seems to be working
	   if (urlVal.isValid(url) == true){ 	   }
	   //if not working, print url
	   else {
		   System.out.println("Expect true, got: " + urlVal.isValid(url) + " for \t" + url);
	   }
   }
   
   public void assert_false(String url, UrlValidator urlVal) {
	   //print nothing if it seems to be working
	   if (urlVal.isValid(url) == false){	   }
	   //if not working, print url
	   else {
		   System.out.println("Expect false, got: " + urlVal.isValid(url) + " for \t" + url);
	   }
   } 
   
   /*
   public void testManualTest()
   {
	   //You can use this function to implement your manual testing	   
	   long options = 
	            (UrlValidator.ALLOW_2_SLASHES
		    + UrlValidator.ALLOW_ALL_SCHEMES
		    + UrlValidator.NO_FRAGMENTS);
		   //schemes
	   String[] schemes = {"http","https", "ftp", "h3t", ""};
	   UrlValidator urlVal = new UrlValidator(schemes, options);
	   // UrlValidator urlVal = new UrlValidator(schemes, options);
	   //UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);	   
	   
	   System.out.println("Manual testing:");
	   
	   assert_true("http://www.google.com", urlVal);
	   assert_false("http://www.google.com/afaswf!*2#@^*#", urlVal);
	   assert_false("http://\\", urlVal);
	   assert_false("http://!", urlVal);
	   
	   assert_true("https://www.google.com", urlVal);
	   assert_false("www.w.google.com", urlVal);
	   assert_false("www.ww.w.googlecom", urlVal);
	   
	   System.out.println();
	   // errors
	   //System.out.println("Expect true, got: " + urlVal.isValid("https://www.google.com"));
	   //System.out.println("Expect true, got: " + urlVal.isValid("ftp://www.google.com"));	   
	    
   }
   */
   
   /*
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	 
	 // http only
	   long options = 
	            (UrlValidator.ALLOW_2_SLASHES
		    + UrlValidator.ALLOW_ALL_SCHEMES
		    + UrlValidator.NO_FRAGMENTS);
		   //schemes
	   String[] schemes = {"http","https", "ftp", "h3t", ""};
	   UrlValidator urlVal = new UrlValidator(schemes, options);
	   
	   
	   System.out.println("First Partition:");
	   
	   // correct schemes
	   assert_true("http://www.google.com", urlVal);
	   assert_false("http://www.google.com/afaswf!*2#@^*#", urlVal); 
	   assert_false("http://", urlVal); 
	   assert_false("http://!", urlVal); 
	   
	   assert_true("ftp://www.google.com", urlVal);
	   assert_false("ftp://www.google.com/afaswf!*2#@^*#", urlVal); 
	   assert_false("ftp://", urlVal); 
	   assert_false("ftp://!", urlVal); 

	   
	   assert_true("https://www.google.com", urlVal);
	   assert_false("https://www.google.com/afaswf!*2#@^*#", urlVal); 
	   assert_false("https://", urlVal); 
	   assert_false("https://!", urlVal); 
 
	   
	   // incorrect schemes
	   assert_false("232f://www.google.com", urlVal);
	   assert_false("232f://www.google.com/afaswf!*2#@^*#", urlVal); 
	   assert_false("232f://", urlVal); 
	   assert_false("232f://!", urlVal);
	   
	   assert_false("12://www.google.com", urlVal);
	   assert_false("12://www.google.com/afaswf!*2#@^*#", urlVal); 
	   assert_false("12://", urlVal); 
	   assert_false("12://!", urlVal);	
	   System.out.println();
	      
   }
   */
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing
	   // all other than http
	   
	   long options = 
	            (UrlValidator.ALLOW_2_SLASHES
		    + UrlValidator.ALLOW_ALL_SCHEMES
		    + UrlValidator.NO_FRAGMENTS);
		   //schemes
	   String[] schemes = {"http","https", "ftp", "h3t", ""};
	   UrlValidator urlVal = new UrlValidator(schemes, options);
	   
	   // path correct
	   //assert_true(, urlVal);
	   //assert_false(, urlVal);	   
	   
	   System.out.println("Second Partition");
	   /*
	   assert_true("http://www.google.com", urlVal);
	   assert_true("http://www.google.com/", urlVal);
	   assert_true("http://www.google.com/images", urlVal);
	   */
	   
	   assert_true("http://www.google.com/images/blah", urlVal);
	   assert_true("http://www.google.com/images/blah/asdf/asdf/", urlVal);
	   assert_true("http://www.google.com/images/blah/asdf/asdf/232/", urlVal);
	   /*
	   // path incorrect
	   assert_false("http://www.google.com/images/blah#(W&&#@($", urlVal);
	   assert_false("http://www.google.com/!!!#", urlVal);
	   assert_false("http://www.google.com/]]", urlVal);
	   assert_false("http://www.google.com/images@#$", urlVal);
	   assert_false("http://www.google.com/images/blah^", urlVal);
	   assert_false("http://www.google.com/images/blah/asdf/asdf/``", urlVal);
	   assert_false("http://www.google.com/images/blah/asdf/asdf/232/()[[", urlVal);
	   System.out.println();
	   */	   
   }   
   //You need to create more test cases for your Partitions if you need to 
   
   public void testUnit() {
	   long options = 
	            (UrlValidator.ALLOW_2_SLASHES
		    + UrlValidator.ALLOW_ALL_SCHEMES
		    + UrlValidator.NO_FRAGMENTS);
		   //schemes
	   String[] schemes = {"http","https", "ftp", "h3t", ""};
	   UrlValidator urlVal = new UrlValidator(schemes, options);	   
	   
	   System.out.println("Unit test");
	   
	   // first 3 valid
	   
	   String [] scheme = {"http", "https", "ftp", "`a", "`b", "`4"};
	   
	   // first 1 valid
	   String [] punctuation = {"://", ":/"};
	   
	   // first 4 valid
	   String [] authority = {"www.google.com", "www.amazon.com", "google.com", "www.google.net"};
			   
	   // first 3 valid
	   String [] path = {"/", "/abc", "/abc/abc"} ;  
	   
	   // first 3 valid
	   String [] query = {"", "?", "?id=5"} ;  
	   
	   boolean good_url = false;
	   
	   // scheme
	   for (int i = 0; i < scheme.length; i++) {
		   // punctuation
		   for (int j = 0; j < punctuation.length; j++) {
			   // authority
			   for (int k = 0; k < authority.length; k++) {
				  // path
				  for (int l = 0; l < path.length; l++) {
					  // query
					   for (int m = 0; m < query.length; m++) {
						   
						   if ((i < 3) &&
								   (j < 1) &&
								   (k < 4) &&
								   (l < 3) &&
								   (m < 3)) {
							   good_url = true;
						   }
						   else {
							   good_url = false;
						   }
						   
						   String url = scheme[i] + punctuation[j] + authority[k] + path[l] + query[m];
						   assert_gen(url, urlVal, good_url);
					   }
				  }
			   }
		   }
	   }
	   
	   
   }
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }   


}
