//Room: /d/dali/sima.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","司马堂");
	set("long",@LONG
这里是大理国司马堂。大理东北强宋，西北吐蕃，历年来边疆宁
靖，皆司马劳顿之功。盖吐蕃垂涎大理已久，每每强辞胁迫，大理不
得不重兵于西北。
LONG);
	set("objects", ([
	    CLASS_D("dali")+"/fanye" : 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "west"  : __DIR__"zonglichu",
	]));
	set("coor/x", -38990);
	set("coor/y", -69990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}