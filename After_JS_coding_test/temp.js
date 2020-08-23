// const main = () => {
const $inpf = document.querySelector(".inp")
const $outpf = document.querySelector('.outp')
const $test1 = document.querySelector(".test1")
const $test2 = document.querySelector(".test2")
const arr = ['testA', 'testB', 'testC', 'testD']
const dict ={
    'testA' : 'A',
    'testB' : 'B',
    'testC' : 'C',
    'testD' : 'D',

}
$inpf.addEventListener('keyup',(e)=>{
    // console.log(e)
    // console.log(e.target)
    var { value } = e.target
    // const { key } = e.keyCode
    console.log(e.key)
    // console.log(e.target)
    // console.log(value)
    if(e.key === 'Enter'){
        console.log('hi')
        $outpf.innerHTML= `<div>${value}</div>`
        console.log($inpf.innerHTML)
        // value = 'melong'

    }else if (e.key ==='ArrowDown'){
        
        $outpf.innerHTML= arr.map(test=>{
            return `<li id="${test}">${test}</li>`;
        }).join('');
        arr.forEach(e=>{
            const element = document.querySelector(`#${e}`)
            element.addEventListener('click',()=> myClickE(e),true)
        })
    }

},true)

const myClickE = (e) => {
    console.log(e)
    $inpf.value = e;
    $outpf.innerHTML= `<div>${e}</div>`
}
// $test1.addEventListener('click', ()=>{
//     $inpf.value = 'melong'
// })
// }

// window.onload(main())
