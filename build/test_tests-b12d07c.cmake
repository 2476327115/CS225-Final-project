add_test( [==[TEST insertVertex #0]==] /workspaces/CS225-Final-project/build/test [==[TEST insertVertex #0]==]  )
set_tests_properties( [==[TEST insertVertex #0]==] PROPERTIES WORKING_DIRECTORY /workspaces/CS225-Final-project/build)
add_test( [==[TEST insertVertex #1]==] /workspaces/CS225-Final-project/build/test [==[TEST insertVertex #1]==]  )
set_tests_properties( [==[TEST insertVertex #1]==] PROPERTIES WORKING_DIRECTORY /workspaces/CS225-Final-project/build)
add_test( [==[TEST insertEdge]==] /workspaces/CS225-Final-project/build/test [==[TEST insertEdge]==]  )
set_tests_properties( [==[TEST insertEdge]==] PROPERTIES WORKING_DIRECTORY /workspaces/CS225-Final-project/build)
<<<<<<< HEAD
add_test( [==[TEST parseFile small]==] /workspaces/CS225-Final-project/build/test [==[TEST parseFile small]==]  )
set_tests_properties( [==[TEST parseFile small]==] PROPERTIES WORKING_DIRECTORY /workspaces/CS225-Final-project/build)
add_test( [==[TEST shortest path]==] /workspaces/CS225-Final-project/build/test [==[TEST shortest path]==]  )
set_tests_properties( [==[TEST shortest path]==] PROPERTIES WORKING_DIRECTORY /workspaces/CS225-Final-project/build)
set( test_TESTS [==[TEST insertVertex #0]==] [==[TEST insertVertex #1]==] [==[TEST insertEdge]==] [==[TEST parseFile small]==] [==[TEST shortest path]==])
=======
add_test( [==[TEST parseFile # small dataset]==] /workspaces/CS225-Final-project/build/test [==[TEST parseFile # small dataset]==]  )
set_tests_properties( [==[TEST parseFile # small dataset]==] PROPERTIES WORKING_DIRECTORY /workspaces/CS225-Final-project/build)
add_test( [==[TEST find important airport # small dataset]==] /workspaces/CS225-Final-project/build/test [==[TEST find important airport # small dataset]==]  )
set_tests_properties( [==[TEST find important airport # small dataset]==] PROPERTIES WORKING_DIRECTORY /workspaces/CS225-Final-project/build)
add_test( [==[BFS # samll dataset]==] /workspaces/CS225-Final-project/build/test [==[BFS # samll dataset]==]  )
set_tests_properties( [==[BFS # samll dataset]==] PROPERTIES WORKING_DIRECTORY /workspaces/CS225-Final-project/build)
add_test( [==[TEST BFS with dest # small dataset]==] /workspaces/CS225-Final-project/build/test [==[TEST BFS with dest # small dataset]==]  )
set_tests_properties( [==[TEST BFS with dest # small dataset]==] PROPERTIES WORKING_DIRECTORY /workspaces/CS225-Final-project/build)
add_test( [==[TEST shortest path # small dataset]==] /workspaces/CS225-Final-project/build/test [==[TEST shortest path # small dataset]==]  )
set_tests_properties( [==[TEST shortest path # small dataset]==] PROPERTIES WORKING_DIRECTORY /workspaces/CS225-Final-project/build)
add_test( [==[TEST construct graph # real data]==] /workspaces/CS225-Final-project/build/test [==[TEST construct graph # real data]==]  )
set_tests_properties( [==[TEST construct graph # real data]==] PROPERTIES WORKING_DIRECTORY /workspaces/CS225-Final-project/build)
add_test( [==[TEST BFS # real data]==] /workspaces/CS225-Final-project/build/test [==[TEST BFS # real data]==]  )
set_tests_properties( [==[TEST BFS # real data]==] PROPERTIES WORKING_DIRECTORY /workspaces/CS225-Final-project/build)
add_test( [==[Find shortest path # real data]==] /workspaces/CS225-Final-project/build/test [==[Find shortest path # real data]==]  )
set_tests_properties( [==[Find shortest path # real data]==] PROPERTIES WORKING_DIRECTORY /workspaces/CS225-Final-project/build)
set( test_TESTS [==[TEST insertVertex #0]==] [==[TEST insertVertex #1]==] [==[TEST insertEdge]==] [==[TEST parseFile # small dataset]==] [==[TEST find important airport # small dataset]==] [==[BFS # samll dataset]==] [==[TEST BFS with dest # small dataset]==] [==[TEST shortest path # small dataset]==] [==[TEST construct graph # real data]==] [==[TEST BFS # real data]==] [==[Find shortest path # real data]==])
>>>>>>> main
