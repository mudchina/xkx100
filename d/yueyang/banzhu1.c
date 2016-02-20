// Room: /d/yueyang/banzhu1.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "斑竹林");
	set("long", @LONG
这里是一片斑竹林。湖风吹来，一阵叶响。斑竹又叫湘妃竹，晋张
晔《博物志》记载：“尧之二女，舜之二妃，曰：‘湘夫人’。帝崩，
二妃啼，以涕挥竹，竹尽斑。”《巴陵县志》载：“君山出斑竹”。它
秀拔莹润，竹竿上点点雅丽的紫色斑点，施肩吾《湘竹词》云：“万古
湘江竹，无穷奈怨何！年年长春笋，只是泪痕多”。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"banzhu2",
		"west"  : __DIR__"banzhu3",
		"south" : __DIR__"banzhu1",
		"north" : __DIR__"erfeimu",
	]));
	set("coor/x", -1670);
	set("coor/y", 2290);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
