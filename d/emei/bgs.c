//Room: bgs.c 报国寺
//Date: Oct. 2 1997 by That

inherit ROOM;
string look_ta();

void create()
{
	set("short","报国寺");
	set("long",@LONG
报国寺是峨眉山最大寺院之一。寺庙倚山建造，弥勒殿、大雄殿、七佛殿
逐级升高，规模宏大。殿内佛像金光闪闪，气宇轩昂。寺内芳草迷径，花开不
绝。这里有一座华严塔(ta)。这里向西，约二里可达伏虎寺。
LONG);
	set("outdoors", "emei");
	set("item_desc", ([
	    "ta" : (: look_ta :),
	]));
	set("objects", ([
		__DIR__+"npc/guest": 1,
		__DIR__+"npc/camel": 1,
		"/clone/misc/dache" : 1,
	]));
	set("exits",([ /* sizeof() == 1 */
		"east"     : __DIR__"bgsgate",
		"west"     : __DIR__"bgsxq",
		"enter"    : __DIR__"dxdian",
		"southwest": __DIR__"milin1",
	]));
//	set("no_clean_up", 0);
	set("coor/x", -6020);
	set("coor/y", -1030);
	set("coor/z", 10);
	setup();
}
string look_ta()
{
	return
"    这是一座十五层的紫铜铸华严塔。塔高七米，塔身周匝共有小佛四千七百\n"
"尊之多，并铸有《华严经》全文两万多字，其冶炼工艺与雕工技巧，已造至极\n"
"至美之境。\n";
}
