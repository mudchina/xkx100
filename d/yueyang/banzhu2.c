// Room: /d/yueyang/banzhu1.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "斑竹林");
	set("long", @LONG
这里是一片斑竹林。湖风吹来，一阵叶响。斑竹又叫湘妃竹，倘若
将斑竹移栽别处，第二年斑迹就会消失得无影无踪，如果再将这株竹子
移回君山，下一年又是斑痕累累的了。唐代高骈曾写有《湘浦曲》云：
“虞帝南巡竞不还，二妃幽怨水云间。当时垂泪知多少？直到如今竹且
斑”。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"banzhu2",
		"west"      : __DIR__"erfeimu",
		"south"     : __DIR__"banzhu1",
		"north"     : __DIR__"banzhu3",
	]));
	set("coor/x", -1660);
	set("coor/y", 2300);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
