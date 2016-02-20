// Room: /d/huanggong/wenyuange.c

inherit ROOM;

void create()
{
	set("short", "文渊阁");
	set("long", @LONG
这里是中央图书馆. 收藏了＜永乐大典＞, ＜四库全书＞, ＜古今
图书集成＞, ＜武英殿聚珍版丛书＞ 等豪著.
LONG
	);
	set("exits", ([
		"north"      : __DIR__"wenhua",
	]));
	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 5220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}