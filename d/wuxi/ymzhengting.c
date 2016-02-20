// Room: /d/wuxi/zhengtang.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "衙门正厅");
	set("long", @LONG
堂上的气氛十分肃穆。几根红漆楹住更是给这里增添了几分庄重。
正墙上悬挂一个横匾，上书“正大光明”四个金光闪闪的大字。现在
不是升堂之时，知府正坐在雕花方案后批阅文书，师爷随侍在后。
LONG
	);
	set("exits", ([
		"south" : __DIR__"yamen",
	]));
	set("objects", ([
		__DIR__"npc/xia": 1,
		__DIR__"npc/shiye": 1,
	]));
	set("coor/x", 380);
	set("coor/y", -780);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
