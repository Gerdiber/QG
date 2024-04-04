let Lpage = document.querySelector('.login')//登录页
let Rpage = document.querySelector('.register')//注册页

let ttr = document.querySelector('.turnToR')//转到注册页
ttr.addEventListener('click', function () {
    Lpage.classList.add('hide')
    Rpage.classList.remove('hide')
})
let ttl = document.querySelector('.turnToL')//转到登录页
ttl.addEventListener('click', function () {
    Rpage.classList.add('hide')
    Lpage.classList.remove('hide')
})

let logindata = document.querySelector('.logindata')//登录页信息提交
logindata.addEventListener('submit', function (e) {
    e.preventDefault()
    let ld = new FormData(logindata)//获取表单数据
    let warn1 = document.querySelector('.lwarn1')//登录警告1
    let warn2 = document.querySelector('.lwarn2')//登录警告2
    if ((ld.get('username') === '') || (ld.get('password') === '')) {
        warn1.classList.remove('hide')//表单内容为空警告
        warn2.classList.add('hide')
    }
    else {
        warn1.classList.add('hide')
        let a = new XMLHttpRequest()
        a.open('POST', 'http://119.91.210.79:3000/login')
        a.send(ld)
        a.onreadystatechange = function () {
            if (a.readyState === 4 && a.status === 200) {
                let result = JSON.parse(a.responseText)
                if (result.status === 0) {
                    warn2.classList.remove('hide')//账号密码错误警告
                }
                else if (result.status === 1) {
                    warn2.classList.add('hide')
                    alert('登录成功')
                }
            }
        }
    }
})

let registerdata = document.querySelector('.registerdata')//注册页信息提交
registerdata.addEventListener('submit', function (e) {
    e.preventDefault()
    let rd = new FormData(registerdata)
    let warn1 = document.querySelector('.rwarn1')
    if ((rd.get('username') === '') || (rd.get('password') === '')) {
        warn1.classList.remove('hide')
    }
    else {
        warn1.classList.add('hide')
        let a = new XMLHttpRequest()
        a.open('POST', 'http://abc.cn')//随便写的,模拟一下接收...
        a.send(rd)
        a.onreadystatechange = function () {
            alert('注册成功')
        }
    }
})
