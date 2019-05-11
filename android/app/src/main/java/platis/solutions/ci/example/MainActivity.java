package platis.solutions.ci.example;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    TextView mApiKeyField;
    TextView mApiSecretField;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mApiKeyField = findViewById(R.id.apiKeyText);
        mApiSecretField = findViewById(R.id.apiSecretText);

        mApiKeyField.setText("API key: " + BuildConfig.apiKey);
        mApiSecretField.setText("API secret: " + BuildConfig.apiSecret);
    }
}
