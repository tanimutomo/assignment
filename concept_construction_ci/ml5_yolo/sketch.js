let video;
let yolo;
let status;
let objects = [];
let personColor = [255, 0, 0];
let otherColor = [0, 255, 0];

function setup() {
    createCanvas(640, 480);
    video = createCapture(VIDEO);

    yolo = ml5.YOLO(video, startDetecting);

    video.hide();
    status = select('#status');
}

function draw() {
    image(video, 0, 0, width, height);
    for (let i = 0; i < objects.length; i++) {
        // Personとそれ以外で描画する線の色を変える
        color = objects[i].className == "person" ? personColor : otherColor;
        console.log(color);
        noStroke();
        fill(color);
        text(objects[i].className, objects[i].x * width, objects[i].y * height - 5);
        noFill();
        strokeWeight(4);
        stroke(color);
        rect(objects[i].x * width, objects[i].y * height, objects[i].w * width, objects[i].h * height);
    }
}

function startDetecting() {
    status.html("Starting Detection...");
    detect();
}

function detect() {
    yolo.detect(function(err, results) {
        objects = results;
        detect();
    });
}