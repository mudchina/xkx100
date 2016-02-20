// Room: /d/yanping/meishanpo.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "梅山坡");
	set("long", @LONG
梅山坡上遍植梅花，漫坡盈野，一到花季，但见群芳绽放，万物
回春，如朝阳遍洒，璀璨无边。“梅山朝晖”位列延平八景之一，年
年吸引无数文人骚客，挥金掷酒，共享花时。
LONG );
	set("exits", ([
		"westup"   : __DIR__"zhouxue",
		"northup"  : __DIR__"beimenling",
		"eastdown" : __DIR__"dongmen",
	]));
	set("outdoors", "yanping");
	set("no_clean_up", 0);
	set("coor/x", 1480);
	set("coor/y", -6170);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
