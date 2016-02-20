// Room: /d/fuzhou/wenrufang.c
// Last Modifyed by Evil on Sep. 10 2002

inherit ROOM;

void create()
{
	set("short", "文儒坊");
	set("long", @LONG
旧名山阴巷，初名儒林坊，以宋代祭酒郑穆居于此，改为文儒坊。
因为坊里除了郑穆之外，还先后住有九门提督、台湾总兵甘国宝，抗倭
名将、七省经略张经，清光绪皇帝老师陈宝琛之父陈承裘，《福建通志
》主编陈衍等儒林名士，故称儒林坊名符其实。 
LONG );
	set("exits", ([
		"east"    : __DIR__"nanhoujie3",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1833);
	set("coor/y", -6330);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
