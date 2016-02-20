// Room: /qingcheng/songfengguan.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "上清殿");
	set("long", @LONG
这里是松风观主殿。殿中陈设奢华，显见青城派财力不菲。正中的
三清座像也塑得极为精致，显微着著，甚有神韵。殿侧两壁挂着几柄旧
剑和一些青城派独门兵器，想来都是本派前辈名宿们当年斩妖除魔时所
佩神兵，供奉于此激励后代弟子。
LONG );
        set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"caochang",
		"north" : __DIR__"garden",
	]));
	set("objects", ([
		__DIR__"npc/hou" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -8080);
	set("coor/y", -830);
	set("coor/z", 90);
	setup();
	"/clone/board/qingcheng_b"->foo();
        replace_program(ROOM);
}