// /d/changan/shuyuan.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "关中书院");
	set  ("long",  @LONG
关中书院是甘陕地区最高学府，建于明万历年间。一位庄重严肃的
老者坐在太师椅上讲学，那就是当今大儒冯先生了。在他的两侧坐满了
求学的学生。
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"north"  :  __DIR__"eastroad2",
	]));
	set("objects",  ([  //sizeof()  ==  4
		__DIR__"npc/feng" : 1,
	]));
	set("coor/x", -5030);
	set("coor/y", 990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
