public class MainActivity extends AppCompatActivity {

    private String InternetAvailableFlag;
    private ProgressDialog pDialog2;
    private String __uberResponse;
    private String status="404";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button button = (Button) findViewById(R.id.lyftApiCall);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                UberCabsETA();

            }
        });
    }

    private String readInputStreamToString(HttpURLConnection connection) { //get response of http request
        String result = null;
        StringBuffer sb = new StringBuffer();
        InputStream is = null;
        try {
            is = new BufferedInputStream(connection.getInputStream());
            BufferedReader br = new BufferedReader(new InputStreamReader(is));
            String inputLine = "";
            while ((inputLine = br.readLine()) != null) {
                sb.append(inputLine);
            }
            result = sb.toString();
        }
        catch (Exception e) {
            Log.i("Lyft Api", "Error reading InputStream");
            result = null;
        }
        finally {
            if (is != null) {
                try {
                    is.close();
                }
                catch (IOException e) {
                    Log.i("Lyft Api", "Error closing InputStream");
                }
            }
        }
        return result;
    }
    private void UberCabsETA(){//to get uber cab info in given source and destination
        class SendPostReqAsyncTask extends AsyncTask<String, Void, String> {
            @Override
            protected void onPreExecute() {
                super.onPreExecute();
                InternetAvailableFlag = "No Internet Connection";
                pDialog2 = new ProgressDialog(MainActivity.this);
                pDialog2.setMessage("Searcing for Uber Cabs.....");
                pDialog2.setIndeterminate(false);
                pDialog2.setCancelable(true);
                pDialog2.show();
            }

            @Override
            protected  String doInBackground(String...params) {

                try {
                /************** For getting response from HTTP URL start ***************/
               String url="https://api.lyft.com/oauth/token";
                URL object = new URL(url);

                HttpURLConnection connection = (HttpURLConnection) object
                        .openConnection();
                // int timeOut = connection.getReadTimeout();
                connection.setReadTimeout(60 * 1000);
                connection.setConnectTimeout(60 * 1000);
                String authorization="i8VynEvD81eC:uGNgniP-9NGGvklH8nXileg4TGymi8_y";
                    byte[] data = authorization.getBytes("UTF-8");
                    String base64 = Base64.encodeToString(data, Base64.DEFAULT);
                String encodedAuth="Basic "+base64;
                connection.setRequestProperty("Authorization", encodedAuth);
                    connection.setRequestProperty("Content-Type", "application/json");
                    connection.setRequestProperty("grant_type", "client_credentials");
                    connection.setRequestProperty("scope", "public");
                    //conn.setRequestProperty("Authorization", "i8VynEvD8leC:uGNgniP-9NGGvklH8nXileg4TGymi8_y");
                    connection.setRequestMethod("POST");
                int responseCode = connection.getResponseCode();
                //String responseMsg = connection.getResponseMessage();

                if (responseCode == 200) {
                    InputStream inputStr = connection.getInputStream();
                    String encoding = connection.getContentEncoding() == null ? "UTF-8"
                            : connection.getContentEncoding();
                    __uberResponse = IOUtils.toString(inputStr, encoding);
                    /************** For getting response from HTTP URL end ***************/

                }
            } catch (Exception e) {
                e.printStackTrace();

            }
                return "success";
            }
/*
            @Override
            protected String doInBackground(String... params) {
                    * curl -X POST -H "Content-Type: application/json" \
     --user "<client_id>:<client_secret>" \
     -d '{"grant_type": "client_credentials", "scope": "public"}' \
     'https://api.lyft.com/oauth/token'

                URL url = new URL("https://api.lyft.com/oauth/token" +
                        "i8VynEvD8leC:uGNgniP-9NGGvklH8nXileg4TGymi8_y");
                //String accessToken = "csBiRmlGA3NE1ztnaDn0H9kLA08iVKrpE3SVc4jj";
                HttpURLConnection conn = (HttpURLConnection) url.openConnection();
                conn.setRequestProperty("Content-Type", "application/json");
                conn.setRequestProperty("grant_type", "client_credentials");
                conn.setRequestProperty("scope", "public");
                conn.setRequestProperty("Authorization", "i8VynEvD8leC:uGNgniP-9NGGvklH8nXileg4TGymi8_y");
                conn.setRequestMethod("POST");

                try {//	android.util.Base64
                    String serviceURL="https://api.lyft.com/oauth/token";
                    URL myURL = new URL(serviceURL);
                    HttpURLConnection myURLConnection = (HttpURLConnection)myURL.openConnection();
                    String userCredentials = "i8VynEvD81eC:uGNgniP-9NGGvklH8nXileg4TGymi8_y";
                    byte[] data = userCredentials.getBytes("UTF-8");
                    String base64 = Base64.encodeToString(data, Base64.DEFAULT);
                    String basicAuth = "Basic " +base64;
//                    String basicAuth = "Basic " + new String(new Base64().encode(userCredentials.getBytes()));
                    myURLConnection.setRequestProperty("Authorization", basicAuth);
                    myURLConnection.setRequestMethod("POST");
                    //myURLConnection.setRequestProperty("Content-Type", "application/x-www-form-urlencoded");
                    myURLConnection.setRequestProperty("Content-Type", "application/json");
                    myURLConnection.setRequestProperty("grant_type", "client_credentials");
                    myURLConnection.setRequestProperty("scope", "public");
                    myURLConnection.setRequestProperty("Content-Length", "" + postData.getBytes().length);
                    myURLConnection.setRequestProperty("Content-Language", "en-US");
                    myURLConnection.setUseCaches(false);
                    myURLConnection.setDoInput(true);
                    myURLConnection.setDoOutput(true);


                    myURLConnection.setConnectTimeout(15000);
                    int httpStatus = myURLConnection.getResponseCode();
                    status=Integer.toString(httpStatus);
                    Log.v("Request Status", "httpStatus " + httpStatus);
                    if (httpStatus == 200) {
                        __uberResponse = readInputStreamToString(myURLConnection);
                        InternetAvailableFlag = readInputStreamToString(myURLConnection);
                    }
                } catch (MalformedInputException e) {
                    e.printStackTrace();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                return "success";
            }

            @Override
            protected void onPostExecute(String result) {
                super.onPostExecute(result);
                Toast.makeText(getApplicationContext(), result+"->"+status, Toast.LENGTH_LONG).show();
                System.out.print(__uberResponse);
                pDialog2.dismiss();
            }
        }
        SendPostReqAsyncTask sendPostReqAsyncTask = new SendPostReqAsyncTask();
        sendPostReqAsyncTask.execute();
    }
}*/
