/*
body -> main -> section#top250 -> div#container

<div class="item">
  <a href="#">
    <div class="cover">
      <img src="http://img7.doubanio.com/view/movie_poster_cover/ipst/public/p1910813120.jpg" alt="">
    </div>
    <div class="detail">
      <h2>霸王别姬</h2>
      <div class="extra">
        <span class="score">9.3分</span>
        <span class="collect">/ 1000收藏</span>
      </div>
      <div class="extra">
        <span class="years">1994 </span>
        <span class="types">/ 剧情 / 爱情 / 同性</span>
      </div>
      <div class="extra">
        <span class="director">导演：陈凯歌</span>
      </div>
      <div class="extra">
        <span class="casts">主演：张国荣、张丰毅、巩俐</span>
      </div>
    </div>
  </a>
</div>
*/

var top250 = {
  init: function() {
    this.$element = $('#top250')
    this.isLoading = false
    this.index = 0
    this.isFinish = false  // 判断数据是否结束，默认情况下没有结束
    this.bind()
    this.start()
  },
  bind: function() {
    // 滚动事件
    var _this = this
    this.$element.scroll(function(){
      _this.start()
      console.log('error...')
    })
  },
  start: function() {
    var _this = this
    this.getData(function(data) {
      _this.render(data)
    })
  },
  getData: function() {
  },
  render: function() {
  },
  isToBottom: function() {
  }
}

var app = {
  init: function() {
    this.$tabs = $('footer>div')
    this.$panels = $('main>section')
    this.bind()

    top250.init() // top250 面板的初始化函数
  },
  bind: function() {
    var _this = this // 这里 _this 与 this 都代表了 bind 这个对象
    this.$tabs.on('click', function() {
      // 这里 _this 仍然代表 bind 这个对象
      // 而 this 此时代表了 $tabs 这个对象了
      $(this).addClass('active').siblings().removeClass('active')
      _this.$panels.eq($(this).index()).addClass('active').siblings().removeClass('active')
    })
  }
}

app.init()
