// Room: /d/huijiang/xingtang.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "刑堂");
	set("long",@LONG
这里是红花会的刑堂。刑堂向来由追命十二郎执掌。会中弟子见到
他的那张冷冰冰的脸，往往都要打冷痉。大抵若有会众违规逃亡，无论
天涯海角，石双英的执法刀总能穷追而至，屡屡不爽。是故，会规才森
然一贯至今。
LONG );
        set("objects", ([
		CLASS_D("honghua")+"/shi-shuangying" : 1,
        ]));
	set("exits", ([
		"north" : __DIR__"wuchang",
	]));
	set("coor/x", -50040);
	set("coor/y", 9130);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
