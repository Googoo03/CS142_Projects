import os

# Set up the environment
env = Environment()

# Add an extra include directory
extra_include_dir = 'header'  # Change this to your actual include directory
env.Append(CPPPATH=[extra_include_dir])


for name in ['Friend_Questionaire', 'Shooting']:
    

    # Compile the C++ source file
    source_file = name+'.cpp'  # Change this to your actual source file
    program = env.Program(name, source_file)

    # Default build target
    Default(program)
