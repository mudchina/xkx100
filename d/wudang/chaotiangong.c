//Room: chaotiangong.c 朝天宫
//Date: Sep 22 1997

inherit ROOM;

void create()
{
	set("short","朝天宫");
	set("long",@LONG
这里已近武当绝顶，只见石梯直耸，危蹬高悬，两旁辅以索链、铁
拦勾连。
LONG);
	set("objects", ([
	     CLASS_D("wudang") +"/qingxu": 1,
	]));

	set("exits",([ /* sizeof() == 1 */
	    "northdown": __DIR__"hutouyan",
	    "south"    : __DIR__"huixianqiao",
	]));
//	set("no_clean_up", 0);
	set("outdoors", "wudang");
	set("coor/x", -2030);
	set("coor/y", -990);
	set("coor/z", 150);
	setup();
	replace_program(ROOM);
}
