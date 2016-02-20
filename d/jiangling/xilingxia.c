//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
  set ("short", "西陵峡");
  set ("long", @LONG
这里两岸怪石嶙峋，险崖峭立，猿猴难攀。滩多流急，以“险”出
名，以“奇”著称，“奇”、“险”化为壮美。这里峡中有峡，大峡套
小峡，滩中有滩，大滩含小滩。展现在你眼前的是色彩斑澜，气象万千
的壮丽画卷。从这里往西是巫峡，北边是一片乱石冈。
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"west" : __DIR__"wuxia",
		"north": __DIR__"shangang2",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1490);
	set("coor/y", -2060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
