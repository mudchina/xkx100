// yuefen.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "岳坟");
        set("long", @LONG
墓道两旁有石虎，石羊，石马和三对翁仲。正中古柏交柯，便是岳飞的
坟墓。墓碑刻着“宋岳鄂王墓”。岳王墓的左面，便是岳飞之子岳云的墓，
墓碑上刻着“宋继忠侯岳云之墓”。在岳坟前面两边四个铁像(statue)。东
首墙上有四个大字(word)。
LONG);
        set("exits", ([
            "south"     : __DIR__"yuelang",
        ]));
        set("item_desc" , ([
            "statue" :
"北边两个是秦桧和他的妻子王氏；南边两个是同谋杀害岳飞的奸臣，
张俊和万俟屑。四个铁像都反剪着手，向岳墓跪着。\n",
            "word"   :
"墙上有“精忠报国”四个大字。这是岳母当年训子时在岳飞背上刻的字。\n",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xihu");
	set("coor/x", 4080);
	set("coor/y", -1400);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
