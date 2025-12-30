#    Tool1CD library provides access to 1CD database files.
#    Copyright © 2009-2017 awa
#    Copyright © 2017-2018 E8 Tools contributors
#
#    This file is part of Tool1CD Library.
#
#    Tool1CD Library is free software: you can redistribute it and/or modify
#    it under the terms of the GNU Lesser General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    Tool1CD Library is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU Lesser General Public License for more details.
#
#    You should have received a copy of the GNU Lesser General Public License
#    along with Tool1CD Library.  If not, see <http://www.gnu.org/licenses/>.

cmake_minimum_required (VERSION 3.10)
project (getcfname)

set (SYSTEMCLASSES_SOURCES SystemClasses/String.cpp
		SystemClasses/System.Classes.cpp
		SystemClasses/System.cpp
		SystemClasses/System.IOUtils.cpp
		SystemClasses/TFileStream.cpp
		SystemClasses/TMemoryStream.cpp
		SystemClasses/TStream.cpp
		SystemClasses/TStreamReader.cpp
		SystemClasses/TStreamWriter.cpp
		SystemClasses/System.SysUtils.cpp
		SystemClasses/GetTickCount.cpp)
set (SYSTEMCLASSES_HEADERS SystemClasses/String.hpp
		SystemClasses/System.Classes.hpp
		SystemClasses/System.hpp
		SystemClasses/System.IOUtils.hpp
		SystemClasses/TFileStream.hpp
		SystemClasses/TMemoryStream.hpp
		SystemClasses/TStream.hpp
		SystemClasses/TStreamReader.hpp
		SystemClasses/TStreamWriter.hpp
		SystemClasses/System.SysUtils.hpp
		SystemClasses/GetTickCount.hpp
		SystemClasses/Exception.hpp)


set (GETCFNAME_SOURCES Base64.cpp BinaryDecimalNumber.cpp BinaryGuid.cpp
	Class_1CD.cpp Common.cpp ConfigStorage.cpp CRC32.cpp DetailedException.cpp Field.cpp FieldType.cpp
	Index.cpp MemBlock.cpp MessageRegistration.cpp Packdata.cpp PackDirectory.cpp
	Parse_tree.cpp SupplierConfig.cpp SupplierConfigBuilder.cpp Table.cpp
	TableFiles.cpp TableFileStream.cpp TableIterator.cpp TableRecord.cpp
	TempStream.cpp UZLib.cpp V8Object.cpp)

set (GETCFNAME_HEADERS Base64.h BinaryDecimalNumber.h BinaryGuid.h Class_1CD.h
	Common.h Constants.h CRC32.h db_ver.h DetailedException.h Field.h FieldType.h
	Index.h MemBlock.h MessageRegistration.h NodeTypes.h Packdata.h PackDirectory.h
	Parse_tree.h SupplierConfig.h SupplierConfigBuilder.h Table.h TableFiles.h
	TableFileStream.h TableIterator.h TableRecord.h TempStream.h UZLib.h V8Object.h)

# .CF API
set (GETCFNAME_SOURCES ${GETCFNAME_SOURCES} cfapi/V8File.cpp cfapi/V8Catalog.cpp cfapi/TV8FileStream.cpp
	cfapi/APIcfBase.cpp cfapi/V8Time.cpp)
set (GETCFNAME_HEADERS ${GETCFNAME_HEADERS} cfapi/V8File.h cfapi/V8Catalog.h cfapi/TV8FileStream.h
	cfapi/APIcfBase.h cfapi/V8Time.h)

set (GETCFNAME_SOURCES ${GETCFNAME_SOURCES} ${SYSTEMCLASSES_SOURCES})
set (GETCFNAME_HEADERS ${GETCFNAME_HEADERS} ${SYSTEMCLASSES_HEADERS})

if (MSVC)
	add_library (getcfname STATIC ${GETCFNAME_SOURCES} ${GETCFNAME_HEADERS})
else()

	if (UNIX)
		set_source_files_properties(${GETCFNAME_SOURCES}
				PROPERTIES COMPILE_FLAGS
				"-fPIC ")
	endif()

	if (NOGUI)
		add_library (getcfname STATIC ${GETCFNAME_SOURCES} ${GETCFNAME_HEADERS})
	else()
		add_library (getcfname SHARED ${GETCFNAME_SOURCES} ${GETCFNAME_HEADERS})
	endif()
endif()

set_target_properties(getcfname PROPERTIES LINKER_LANGUAGE CXX)

add_executable(getcfname_exe main.cpp)
target_link_libraries(getcfname_exe getcfname)

add_definitions(-DBOOST_UUID_FORCE_AUTO_LINK)
add_definitions(-Dgetcfname)
find_package (Boost 1.53 REQUIRED COMPONENTS filesystem regex system)
include_directories (${Boost_INCLUDE_DIRS})
target_link_libraries (getcfname ${Boost_LIBRARIES})

find_package (ZLIB REQUIRED)
include_directories (${ZLIB_INCLUDE_DIRS})
target_link_libraries (getcfname ${ZLIB_LIBRARIES})

if (NOT MSVC)
	if (NOT NOGUI)
		install (TARGETS getcfname DESTINATION lib)
	endif()
endif()
