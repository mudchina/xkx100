// fu-huating 花厅
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "花厅");
        set("long", @LONG
这里是这户人家喝酒赏月的所在，一个小亭子建造在厅的中央，
四周围绕着一些葡萄藤(teng)。一阵微风吹过，空气中似乎有隐隐
的花香飘来，中人欲醉。
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "south" : __DIR__"fu-ceting",
                "west" : __DIR__"fu-xiaoyuan",
        ]));
        set("no_clean_up", 0);
        set("item_desc", ([
            "teng": "这些藤好象长得有些日子了，密不透风，夏天呆在藤下肯定阴凉极了。\n"
        ]) );
	set("coor/x", -3120);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}