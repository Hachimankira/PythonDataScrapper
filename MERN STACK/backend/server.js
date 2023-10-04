require('dotenv').config()

const express = require('express')
const mongoose = require('mongoose')
const workoutRoutes = require('./routes/workout')

//express app
const app = express()

//middleware
app.use(express.json())

app.use((req, res, next) => {
    console.log(req.path, req.method)
    next();
})
//routes
// app.get('/', (req,res) =>{
//     res.json({mssg: "Welcome to the App"})
// }) //instead of using this we will be using the below:

app.use('/api/workouts', workoutRoutes) //this will work when the user gets into the first parameter

//connect to db
mongoose.connect(process.env.MONGO_URI)
    .then(() => {
        // listen for requests
        app.listen(process.env.PORT, () => {
            console.log('connected to DB & listening on port ', process.env.PORT)
        })
    })
    .catch((error) => {
        console.log(error)
    })



