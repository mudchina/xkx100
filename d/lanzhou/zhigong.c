//  Room:  /d/lanzhou/zhigong.c

inherit  ROOM;

void  create  ()
{
	set("short",  "至公堂");
	set("long",  @LONG
这里是方圆百里仅有的贡院，为朝廷贡院应试之所。里面不时传来
学生们抑扬顿挫的读书声。据说本院建于光绪元年，牌匾上“至公堂”
三大个字还是陕甘总督左宗棠亲手所题。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north" : __DIR__"cuiying",
	]));
	set("no_clean_up", 0);
	set("coor/x", -9300);
	set("coor/y", 2680);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}