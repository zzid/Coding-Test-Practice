// document.onload = solution();

function solution(){
    var mystr = "10,000원";
    var regex = /[\D]/g
    // var cleaned = regex.exec(mystr);
    var cleaned = mystr.replace(regex, '');
    console.log(cleaned)
    return cleaned;
}
solution(); 
//ctrl + alt + n