//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{

	set ("short", "元妙观");
	set ("long", @LONG
这里原称玄妙观，建于唐开元年间，原来在荆州城西北，后迁至此。
为避康熙皇帝玄烨之名讳，将“玄”改为“元”。眼前一座四角攒尖顶
的三层楼阁是玉皇阁，后面是玄武殿，建在崇台之上，古朴雅致，巍峨
庄严。
LONG);
	set("exits", ([ 
      "west" : __DIR__"dongjie1",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1460);
	set("coor/y", -2020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
