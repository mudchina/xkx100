// Room: /d/xingxiu/xxroad3.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "六盘山");
	set("long", @LONG
这是一座不太高的小山。山顶望去，瓦蓝的天空 (sky)飘着几朵淡
淡的白云。一群大雁发出「嘎嘎」的叫声，从头上飞过。西面山下长城
的残垣断壁依稀可辨。长城的尽头是一座雄伟的关隘。路旁有一处悬崖
之上刻着首词(poem)。
LONG );
	set("exits", ([
		"westdown"  : __DIR__"jiayuguan",
		"northdown" : "/d/yongdeng/yongdeng",
		"southdown" : __DIR__"xxroad2",
	]));

	set("item_desc", ([ 
"poem" : "崖壁上刻着一首清平乐：

  何  今  红  六  屈  不  望  天
  时  日  旗  盘  指  到  断  高
  缚  长  漫  山  行  长  南  云
  得  缨  卷  上  程  城  飞  淡
  苍  在  西  高  二  非  雁  
  龙  手  风  峰  万  好  
                      汉

你现在是好汉了！
\n",
"sky" : "
                              \\/             \\/
                   /*=*         \\/       \\/
                   (*=*=)         \\/  \\/
               {/*=**=/            \\/
                         __
                        /\\.\\_   
               /\\  /\\  /  ...\\   /\\
              / .\\/ .\\/    .. \\_/ .\\
             /  ..\\  /    ... . \\  .\\      /\\
            /凸凸凸\\/凸凸凸. ..凸\\凸.\\    / .\\  
  _凸凸凸凸/     ..凸     凸凸凸..\\__.\\凸/  ..\\_凸凸凸凸凸凸凸凸凸凸凸凸_\n\n"
]));

	set("no_clean_up", 0);
	set("outdoors", "silu");

	set("coor/x", -9600);
	set("coor/y", 3000);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}
