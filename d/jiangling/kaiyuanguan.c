//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "开元观");
	set ("long", @LONG
这是一座著名的古道观，远望山门，隐约可见观内几座大殿重檐错
落，雄浑壮观。观内四壁刻有文人墨客的题词，摆放的钟、炉、铁镬等
等，无不古意盎然。
LONG);
	set("exits", ([ 
                "east"  : __DIR__"xijie4",
	]));
	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1510);
	set("coor/y", -2040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}