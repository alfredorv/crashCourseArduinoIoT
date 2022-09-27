const express = require('express');
const app = express();
const port = 4000;

// Middlewares
app.use(express.json());
app.use(express.urlencoded({ extended: false }));

// Routes
app.use(require('./routes/routes'));

app.listen(port);
console.log('Server on port ' + port);
