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

        // If you are getting a compilation error in the two lines below
        // then you need make a copy of the `gradle.properties.no.git` file in the
        // root of this application to the same folder and call it `gradle.properties`.
        // There you can define your (secret) API keys without having to version control
        // them. Please note that this is not how you should store keys for an
        // application that will be distributed as an `.apk` since the keys can
        // eventually be decompiled.
        mApiKeyField.setText("API key: " + BuildConfig.apiKey);
        mApiSecretField.setText("API secret: " + BuildConfig.apiSecret);
    }
}
