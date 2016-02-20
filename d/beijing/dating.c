#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
这里就是天下闻名的天地会青木堂大厅，只见一张板桌上供着两个
灵牌，中间一个写着“大明天子之位”，侧边一个写着“大明延平郡王
郑之位”。此外有一块白木 (baimu)，上面密密麻麻全是血字。厅侧有
一副对联(duilian)。东边是侧厅，南北都是暗道。
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"andao10",
		"north" : __DIR__"tuzai",
		"east"  : __DIR__"ceting",
		"west"  : __DIR__"lianwu",
	]));
	set("item_desc", ([
		"baimu" : 
HIR "\n  只见白木上写道：天地万有，回复大明。吾人当同生共死，\n"
"仿桃园故事，约为兄弟，姓洪名金兰，合为一家。拜天为父，\n"
"拜地为母, 日为兄，月为姊妹，焚香设誓，一雪前耻，顺天\n"
"行道，恢复明朝。歃血为盟，神明降鉴。\n" NOR,
	"duilian":
HIC "\n地振高冈，一派溪山千古秀\n" NOR +
HIG "门朝大海，三河合水万年流\n" NOR,
	]));
	set("objects", ([
		CLASS_D("yunlong") + "/chen" : 1
	]));
	set("coor/x", -212);
	set("coor/y", 4015);
	set("coor/z", -20);
	setup();
	"/clone/board/tiandihui_b"->foo();
}

int valid_leave(object me, string dir)
{
	if (dir== "north")
		message("vision","眨眼间，屠宰场里突然多了一个人。\n","/d/beijing/tuzai");
	return ::valid_leave(me, dir);
}