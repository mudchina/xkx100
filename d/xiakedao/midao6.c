// midao6.c 石洞

inherit ROOM;

string* books = ({
        "/clone/book/book-bamboo",
//        "/clone/book/book-paper",
        "/clone/book/book-silk",
        "/clone/book/book-stone",
        "/clone/book/book-iron",
});

void create()
{
        set("short", "石洞");
        set("long", @LONG
这是一个石洞，地上和石壁满是灰尘，看得出好久没人来过了
靠左侧石壁是一排书架，上面也满是灰尘，还有一些破旧的书籍。
墙角有一张石床。虽然很脏，却也能休息。
LONG );
        set("exits", ([
                "west" : __DIR__"midao7",
        ]));
        set("sleep_room", 1);
        set("objects", ([
                books[random(sizeof(books))] : 1,
                books[random(sizeof(books))] : 1,
        ]));
	set("coor/x", -3090);
	set("coor/y", -25000);
	set("coor/z", -20);
	setup();
        replace_program(ROOM);
}