const btn = document.querySelector("#btn1");
const output = document.querySelector("#outputTxT")
const output2 = document.querySelector('#outputTxT2')

let per;

btn.addEventListener("click", function() {
    let target = 75;
    let bunk = 0;
    let moreBunk = 0;
    let extAtn = 0;

    var atn = parseInt(document.querySelector("#AttendedB").value);
    var total = parseInt(document.querySelector("#TotalB").value);
    moreBunk = parseInt(document.querySelector('#moreBunk').value);
    target = parseInt(document.querySelector("#targetAtd").value);

    if (!(isNaN(moreBunk))){
        total = total + moreBunk;
        per = (atn / total) * 100;
        output.innerHTML = `After Bunking ${moreBunk} classes your attendence will be ${per.toFixed(2)}.`
        output2.innerHTML =  ``;
    }
    else {

        if (isNaN(target)) {
            target=75;
        }
    
        per = (atn / total) * 100;
    
        if (per >= target) {
            while (per >= target) {
                bunk = bunk + 1;
                total = total + 1;
                per = (atn / total) * 100;
            };
            bunk--;
            total--;
            per = (atn / total) * 100;
    
            output.innerHTML = `You can bunk ${bunk} classes.`;
            output2.innerHTML =  `After that your attendence will be ${per.toFixed(2)}.`;
    
        } else {
            while (per < target){
                atn++;
                extAtn++;
                total++;    
                per = (atn/total) * 100;
            }
            per = (atn/total) * 100;
            output.innerHTML = `You will have to attend ${extAtn} more classes.`;
            output2.innerHTML =  `After that your attendence will be ${per.toFixed(2)}.`;
        }
    }
});