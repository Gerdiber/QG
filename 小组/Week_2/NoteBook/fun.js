const test = JSON.parse(localStorage.getItem('noteData'))
let ncl = document.querySelector('ul')
let noteList = []
if (test === null) {}
else {
    noteList = test
    render()
}

let txt = document.querySelector('.NText')
txt.addEventListener('keyup', function (e) {
    if (e.key === 'Enter') {
        if (txt.value === '\n') { txt.value = "" }
        else {
            let notestr = txt.value
            noteList.unshift(notestr.replace("\n", ""))
            txt.value = ""
            render()
        }
    }
})

let serh = document.querySelector('.NSearch')
serh.addEventListener('keyup', function (e) {
    if (e.key === 'Enter') {
        let noteA = document.querySelectorAll('.Active')
        for(let i=0; i<noteA.length; i++){
            noteA[i].classList.remove('Active')
        }
        if (serh.value === '') {}
        else {
            let na = document.querySelectorAll('.NContent')
            for (let i=0;i<noteList.length;i++){
                if(noteList[i].includes(serh.value)){
                    na[i].classList.add('Active')
                }
            }
        }
    }
})

ncl.addEventListener('click', function (e) {
    if (e.target.dataset.fc === 'del') {
        noteList.splice(e.target.dataset.id, 1)
        render()
    }
    else if (e.target.dataset.fc === 'edit') {
        let str = prompt("进行更改", noteList[e.target.dataset.id])
        if (str === null) { }
        else {
            noteList[e.target.dataset.id] = str
            render()
        }
    }
})

function render() {
    localStorage.setItem('noteData', JSON.stringify(noteList))
    ncl.innerHTML = ``
    for (let i = 0; i < noteList.length; i++) {
        const nc = document.createElement('li')
        nc.innerHTML = `
        <button class="del" data-id=${i} data-fc="del">删除</button>
        <button class="edit" data-id=${i} data-fc="edit">修改</button>
        <div class="NContent">${noteList[i]}</div>
        `
        ncl.appendChild(nc)
    }
}