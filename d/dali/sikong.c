//Room: /d/dali/sikong.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","司空堂");
	set("long",@LONG
这里是大理国司空堂。堂内无余物，四壁却堆满了书籍。想来主
人爱书如命，即便工余亦手不释卷。
LONG);
	set("objects", ([
	    CLASS_D("dali")+"/batianshi" : 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "south"  : __DIR__"zonglichu",
	]));
	set("coor/x", -39000);
	set("coor/y", -69980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}